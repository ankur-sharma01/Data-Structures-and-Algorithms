// #include<iostream>
// using namespace std;

// rat in a maze problem: BACKTRACKING

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if the next move is valid
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
            return true;
        }
        return false;
    }

    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        // BASE CASE: If destination reached
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // 4 Choices: Down, Left, Right, Up (D, L, R, U order for sorted results)

        // 1. Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, m)) {
            solve(m, n, ans, newx, newy, visited, path + 'D');
        }

        // 2. Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, visited, m)) {
            solve(m, n, ans, newx, newy, visited, path + 'L');
        }

        // 3. Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, visited, m)) {
            solve(m, n, ans, newx, newy, visited, path + 'R');
        }

        // 4. Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, visited, m)) {
            solve(m, n, ans, newx, newy, visited, path + 'U');
        }

        // BACKTRACK: Unmark this cell before going back up the recursion tree
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        
        // If the start or end is blocked, no path is possible
        if (m[0][0] == 0 || m[n-1][n-1] == 0) return ans;

        vector<vector<int>> visited = m;
        // Initialize visited matrix with 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }

        string path = "";
        solve(m, n, ans, 0, 0, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;

    Solution obj;
    vector<string> result = obj.findPath(maze, n);

    if (result.empty()) cout << "No path found";
    else {
        for (string path : result) cout << path << " ";
    }
    return 0;
}


marpul zip
|

marpul/                                 

│

├── CMakeLists.txt                      ← build definition: 3 binaries + all deps

│

├── SETUP_GUIDE.md                      ← installation guide

├── AUTONOMOUS_SETUP_GUIDE.md           ← extended autonomy setup

│

├── include/marpul/                     ← ALL headers (included by every .cpp)

│   ├── types.hpp                       ← enums, Position, SessionState, phi_buy_fraction

│   ├── constants.hpp                   ← every numeric constant — single source of truth

│   ├── stock_state.hpp                 ← StockState struct (per-stock live state, ~3KB each)

│   ├── aggressor_engine.hpp            ← phi aggressor, CVD, ALCT, NMD, IFT (Core 1)

│   ├── obi_engine.hpp                  ← 5-level weighted OBI, cancel-rate filter (Core 1)

│   ├── vwap_engine.hpp                 ← VWAP, EMA-9, vwap_sigma, TPS (Core 1)

│   ├── stage_gates.hpp                 ← all 7 stage gate functions, CS formula, SL (Core 1)

│   ├── mdb_engine.hpp                  ← mid-day breakout engine, mdb_trail_pct (Core 1)

│   ├── cross_asset_engine.hpp          ← 7 rubber-band XAsset pairs, Z_spread (Core 1)

│   ├── commodity_map.hpp               ← 18 MCX/CDS instruments, basket weights

│   ├── peer_map.hpp                    ← sector definitions, duopoly pairs

│   ├── tick_serializer.hpp             ← RawTick, OrderBook, Shoonya JSON → RawTick

│   ├── disruptor.hpp                   ← LMAX Disruptor ring buffer (Core 0 → Core 1)

│   ├── zmq_publisher.hpp               ← ZeroMQ PUB/SUB wrapper, all publish methods

│   ├── paper_trading.hpp               ← paper mode, PaperLedger, slippage model

│   └── cpu_utils.hpp                   ← CPU affinity, SCHED_FIFO setup

│

├── src/

│   ├── main.cpp                        ← marpul_main entry: reads mmap, starts Core 0 & 1

│   │

│   ├── core0/                          ← Core 0 (CPU 0, SCHED_FIFO 99)

│   │   ├── websocket_consumer.cpp      ← Shoonya WebSocket client, reconnect logic

│   │   └── shoonya_parser.cpp          ← JSON → RawTick → Disruptor ring

│   │

│   ├── core1/                          ← Core 1 (CPU 1, SCHED_FIFO 99)

│   │   └── calculation_engine.cpp      ← all signal logic, stage gates, ZMQ publish

│   │

│   ├── exec/                           ← marpul_exec binary (Core 2, SCHED_FIFO 99)

│   │   ├── main.cpp                    ← ZMQ subscriber, process_message, SYS.* handlers

│   │   ├── execution_engine.cpp        ← REST orders, FOK poll, position registration

│   │   ├── post_entry_monitor.cpp      ← all 12 exit checks, trailing SL, close_full

│   │   ├── risk_engine.cpp             ← kill switch, PnL, Nifty 5-min drop guard

│   │   └── kelly_sizer.cpp             ← 3-phase Kelly sizing, per-regime rings

│   │

│   ├── ops/                            ← marpul_ops binary (Core 3, normal priority)

│   │   ├── main.cpp                    ← daily orchestration, storage subscriber loop

│   │   ├── premarket.cpp               ← baseline_compute, IEP poll, mmap_write, cold_start_fix

│   │   ├── storage.cpp                 ← Redis XADD pipeline, TimescaleDB writer loop

│   │   ├── auto_upgrade.cpp            ← Bayesian threshold update, self_test, regime_classify

│   │   └── telegram_alert.cpp          ← nightly report, threshold change proposals, poll

│   │

│   └── shared/

│       └── globals.cpp                 ← g_ring, g_universe[], g_session, g_publisher (shared across cores)

│

└── scripts/

    ├── setup.sh                        ← ONE-TIME: installs everything on Oracle ARM

    ├── schema.sql                      ← ONE-TIME: creates all TimescaleDB tables + indexes

    ├── redis.conf                      ← Redis config (no persistence during market hours)

    ├── shoonya_login.py                ← runs daily at 8:25 IST, writes fresh session token

    ├── daily_start.sh                  ← cron 0 3 * * 1-5: login + start all 3 services

    ├── daily_stop.sh                   ← cron 10 10 * * 1-5: stop marpul_exec + marpul_main

    ├── keepalive.sh                    ← 24/7: Oracle idle prevention (CPU + memory + network)

    └── marpul-keepalive.service        ← systemd unit for keepalive.sh (Restart=always)