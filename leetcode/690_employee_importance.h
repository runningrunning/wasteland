/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id)
    {
        int all = 0;
        set<int> eid;
        eid.insert(id);
        set<int>::iterator eit;

        while (!eid.empty())
        {
            bool find = false;
            for (vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++ it)
            {
                eit = eid.find((*it)->id);
                if (eit )
                {
                    find = true;
                    eid.erase(eit);
                    all += (*it)->importance;
                    for (vector<int>::iterator idt = (*it)->subordinates.begin(); idt != (*it)->subordinates.end(); ++ idt)
                        eid.insert(*idt);
                }
            }

            if (!find)
                break;
        }
        return all;
    }
};
