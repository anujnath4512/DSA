class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {

            // Positive asteroid → push directly
            if (x > 0) {
                st.push(x);
            }

            // Negative asteroid
            else {
                bool destroyed = false;

                while (!st.empty() && st.top() > 0) {

                    // Top asteroid is smaller
                    if (st.top() < -x) {
                        st.pop();
                    }

                    // Both are equal
                    else if (st.top() == -x) {
                        st.pop();
                        destroyed = true;
                        break;
                    }

                    // Top asteroid is bigger
                    else {
                        destroyed = true;
                        break;
                    }
                }

                // Current asteroid survived
                if (!destroyed) {
                    st.push(x);
                }
            }
        }

        vector<int> ans(st.size());

        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};