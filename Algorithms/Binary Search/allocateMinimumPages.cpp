// GFG Allocate Minimum Pages

// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// All books must be allocated.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. If it is not possible to allocate books to all students, return -1;

// Note: Test cases are generated such that the answer always fits in a 32-bit integer.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.


class Solution {
public:
    bool fun(vector<int> &arr, int n, long long guess, int k) {
        int student = 1;
        long long pages = 0;
        for(int i = 0; i < n; i++)
        {
            if(pages + arr[i] <= guess)
            {
                pages = pages + arr[i];
            } else
            {
                student++;
                pages = arr[i];
                if(student > k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    long long findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k) return -1;
        long long low = 0, high = 0;
        for(int i = 0; i < n; i++)
        {
            low = max(low, (long long)arr[i]); //TODO:
            high = high + arr[i];
        }
        long long res = -1;
        while(low <= high)
        {
            long long guess = low + (high - low)/2;
            if(fun(arr, n, guess, k))
            {
                res = guess;
                high = guess - 1;
            } else
            {
                low = guess + 1;
            }
        }
        return res;
    }
};
//TODO:
// We use `(long long)arr[i]` because C++'s `std::max()` function requires **both arguments to be of the exact same data type**.

// Since `low` is a `long long` and `arr[i]` is an `int` (from `vector<int>`), writing `std::max(low, arr[i])` without casting will trigger a **compiler error**:

// ```text
// error: no matching function for call to 'max(long long&, int&)'

// ```

// The `std::max(T a, T b)` template cannot automatically decide whether `T` should be `int` or `long long`. Explicitly casting `(long long)arr[i]` ensures both arguments are `long long`.

// ### Cleaner Alternatives in C++

// Instead of a C-style cast, you can also write:

// 1. **Explicit Template Parameter:**
// ```cpp
// low = max<long long>(low, arr[i]);

// ```


// 2. **`static_cast` (Preferred C++ style):**
// ```cpp
// low = max(low, static_cast<long long>(arr[i]));

// ```







// now we will move to another project, check this repo : https://github.com/perryvegehan/UPI_Without_Internet.git
// and we will add the pasted functionality with this project and the new project will be ready. provide readme and detailed explanation.

// Here is the exact technical specification for the AI component. You can pass this directly to another AI tool as the blueprint for building the ML/Fraud Detection module.

// ---

// # AI/ML Architecture Specification: Offline-to-Cloud Fraud & Anomaly Detection

// ### 1. High-Level Role of AI in this Project

// The AI model acts as a **Cloud-Side Fraud Inspector** residing inside an **AWS Lambda worker function**.

// Because offline transactions happen without live bank validation, malicious users might attempt to tamper with offline logs, generate rapid fake transactions, or execute impossible spending bursts before reconnecting to the internet.

// The AI model evaluates incoming deferred transaction batches **after SQS queuing, but before writing updates to the Amazon DynamoDB ledger**. If a batch exhibits suspicious behavior, the AI flags or diverts the transaction to prevent bad data or double-spending from altering the main ledger.

// ---

// ### 2. Technical Stack & Model Selection

// * **Framework:** `scikit-learn` (Python 3.11 environment in AWS Lambda)
// * **Model Type:** **Isolation Forest** (`sklearn.ensemble.IsolationForest`) — Unsupervised Anomaly Detection.
// * **Storage & Serialization:** Model trained locally/offline, saved as a `.joblib` binary file, and bundled into an AWS Lambda Layer or S3 bucket for low-latency loading.

// ---

// ### 3. Feature Extraction (Model Input Vector)

// When a client device regains internet connectivity, it uploads a JSON payload containing an array of offline transactions. The Lambda worker converts this raw JSON into a **7-dimensional numerical feature vector** for the model:

// ```python
// feature_vector = [
//     time_delta_since_last_sync,  # Seconds elapsed between current sync and previous sync
//     offline_tx_count_in_batch,   # Total number of transactions in this single offline batch
//     total_batch_amount,          # Sum of all transaction amounts in the batch (INR)
//     max_single_tx_amount,        # Highest individual transaction amount in the batch
//     avg_time_between_offline_txs,# Average time gap between offline payments in the batch
//     nonce_gap_count,             # Number of missing/out-of-order sequence nonces
//     velocity_ratio               # (total_batch_amount / time_delta_since_last_sync)
// ]

// ```

// ---

// ### 4. Step-by-Step AI Execution Workflow Inside AWS Lambda

// ```
// [ Raw Payload from SQS FIFO ]
//             │
//             ▼
//  [ Parse JSON & Validate HMAC ]
//             │
//             ▼
// [ Extract Feature Vector for AI ]
//             │
//             ▼
// [ Load Model: isolation_forest.joblib ]
//             │
//             ▼
//    Predict Anomaly Score
//             │
//    ┌────────┴────────┐
//    ▼                 ▼
// [ Normal (1) ]   [ Anomaly (-1) ]
//    │                 │
//    ▼                 ▼
// [ Commit to      [ Divert to DLQ & Flag ]
//  DynamoDB ]       Account in DynamoDB ]

// ```

// #### Step A: Feature Processing & Prediction Code (Python / Lambda)

// ```python
// import json
// import joblib
// import numpy as np

// # Load pre-trained model once outside handler (Lambda Warm Start)
// model = joblib.load('/opt/ml/isolation_forest.joblib')

// def lambda_handler(event, context):
//     for record in event['Records']:
//         payload = json.loads(record['body'])
        
//         # 1. Feature Engineering from incoming JSON payload
//         tx_list = payload['transactions']
//         time_delta = payload['sync_timestamp'] - payload['last_sync_timestamp']
//         batch_count = len(tx_list)
//         total_amount = sum(tx['amount'] for tx in tx_list)
//         max_amount = max(tx['amount'] for tx in tx_list) if tx_list else 0
        
//         # Calculate time differences between sequential offline payments
//         timestamps = [tx['timestamp'] for tx in tx_list]
//         time_diffs = np.diff(sorted(timestamps)) if len(timestamps) > 1 else [0]
//         avg_gap = float(np.mean(time_diffs))
        
//         nonce_gaps = payload.get('nonce_gap_count', 0)
//         velocity = total_amount / max(time_delta, 1)
        
//         # Construct Feature Array
//         features = np.array([[
//             time_delta, batch_count, total_amount, 
//             max_amount, avg_gap, nonce_gaps, velocity
//         ]])
        
//         # 2. Run Inference (-1 = Anomaly, 1 = Normal)
//         prediction = model.predict(features)[0]
//         anomaly_score = model.decision_function(features)[0]
        
//         # 3. Decision Logic
//         if prediction == -1:
//             # Route to Fraud/Dispute Queue & Flag Account
//             flag_suspicious_account(payload['user_id'], anomaly_score)
//             send_to_dead_letter_queue(payload)
//             return {"status": "FLAGGED", "reason": "Anomaly Detected by AI"}
            
//         # 4. Proceed to DynamoDB Atomic Settlement
//         commit_to_dynamodb_ledger(payload)
        
//     return {"status": "SUCCESS"}

// ```

// ---

// ### 5. Training Script Template (Run locally to generate `.joblib` file)

// Pass this to the building AI to generate the dummy training pipeline:

// ```python
// import numpy as np
// import pandas as pd
// from sklearn.ensemble import IsolationForest
// import joblib

// # Synthetic normal transaction behavior
// normal_data = pd.DataFrame({
//     'time_delta': np.random.uniform(300, 86400, 1000),      # Sync every 5 min to 24 hrs
//     'batch_count': np.random.randint(1, 10, 1000),         # 1-10 offline txs
//     'total_amount': np.random.uniform(50, 2000, 1000),     # Small offline amounts
//     'max_amount': np.random.uniform(20, 500, 1000),
//     'avg_gap': np.random.uniform(60, 3600, 1000),
//     'nonce_gaps': np.zeros(1000),                          # No missing nonces
//     'velocity': np.random.uniform(0.001, 1.0, 1000)
// })

// # Train Isolation Forest
// clf = IsolationForest(contamination=0.02, random_state=42)
// clf.fit(normal_data)

// # Export trained model artifact for Lambda
// joblib.dump(clf, 'isolation_forest.joblib')

// ```