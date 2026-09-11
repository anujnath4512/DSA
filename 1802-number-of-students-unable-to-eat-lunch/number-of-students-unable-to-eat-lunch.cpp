class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;

        // Put all students into queue
        for (int student : students) {
            q.push(student);
        }

        int i = 0;      // current sandwich
        int count = 0;  // consecutive students who refused

        while (!q.empty()) {

            if (q.front() == sandwiches[i]) {

                // Student takes sandwich
                q.pop();
                i++;

                // Reset because progress was made
                count = 0;
            }
            else {

                // Student goes to back of queue
                int student = q.front();
                q.pop();
                q.push(student);

                count++;
            }

            // Everyone remaining has refused this sandwich
            if (count == q.size()) {
                break;
            }
        }

        return q.size();
    }
};