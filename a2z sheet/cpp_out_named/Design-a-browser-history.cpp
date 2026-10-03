// LC 1472

// what what we need to design:

    // browser homepage
    // visit (URL)
    // back (steps)
    // forward (steps)


class BrowserHistory {
private:
    struct Node {
        string url;
        Node* prev;
        Node* next;
        /*
        Node(string val): This defines a constructor function that takes a single string parameter (val), which is the URL string passed in (e.g., "google.com").
        :: The colon introduces the Member Initializer List. It tells C++: "Before executing the function body, initialize the struct's member variables directly with these values."
        url(val): Assigns the input string val to the member variable url.
        prev(nullptr): Sets the prev pointer to nullptr (0/null).
        next(nullptr): Sets the next pointer to nullptr (0/null).
        {}: An empty function body. Because all variables were initialized in the initializer list, no extra work needs to be done inside the body {}.
        */
        Node(string val) : url(val), prev(nullptr), next(nullptr) {}
    };

    Node* curr;

public:
    // constructor:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        // delete the next nodes from memory:
        Node* runner = curr->next;
        while (runner)
        {
            Node* temp = runner->next;
            delete runner;
            runner = temp;
        }

        Node* newTab = new Node(url);
        curr->next = newTab;
        newTab->prev = curr;
        curr = newTab;
    }
    
    string back(int steps) {
        while (steps)
        {
            if (curr->prev)
            {
                curr = curr->prev;
                steps--;
            }
            else
            {
                break;
            }
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (steps)
        {
            if (curr->next)
            {
                curr = curr->next;
                steps--;
            }
            else
            {
                break;
            }
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */