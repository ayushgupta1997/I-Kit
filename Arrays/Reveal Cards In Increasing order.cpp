// Array Problem
/*Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.

Print the order such that they follow a increasing order of the sequence:


*/
class Solution {
public:

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        int n = deck.size();
        deque<int> deq;
        deq.push_back(deck[0]);
        for (int i = 1; i < n; i++) {
            deq.push_front(deq.back());
            deq.pop_back();
            deq.push_front(deck[i]);
        }
        vector<int> ans(deq.begin(), deq.end());
        return ans;
    }
};


// Method 2 : using Queue : Runtime is  8ms
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        queue<int> que;
        for (int i = 0; i < n; i++) {
            que.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {   // simply doing operations n times and ensuring that we get the correct increasing order in the ans array
            int temp = (int)que.front();
            que.pop();
            ans[temp] = deck[i];
            temp = que.front();
            que.pop();
            que.push(temp);
        }
        return ans;
    }
};
