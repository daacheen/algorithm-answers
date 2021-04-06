#include "cppincludes.h"

/*

dp[arr] = 1+min(dp[arr-person[i]] for i in person.length)


*/

class Solution {

  public:
    int find_index(vector<string> &req_skills, string &skill) {
        for (int i = 0; i < req_skills.size(); i++) {
            if (req_skills[i] == skill) {
                return i;
            }
        }
        return -1;
    }

    vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                       vector<vector<string>> &people) {
        vector<bool> skills(req_skills.size(), true);
        vector<bool> available(people.size(), true);

        // mapping people's skill to index in skills
        vector<vector<int>> people_index(people.size());
        for (int i = 0; i < people.size(); i++) {
            for (string &s : people[i]) {
                people_index[i].push_back(find_index(req_skills, s));
            }
        }

        auto result = rec(skills, available, skills.size(), people_index);
        return vector<int>(result.begin(), result.end());
    }

    unordered_set<int> rec(vector<bool> &skills, vector<bool> &available,
                           int needSkills, vector<vector<int>> &people) {
        if (needSkills == 0) {
            return {};
        }

        int minIndex, minResult = INT_MAX;
        unordered_set<int> minList;
        for (int index = 0; index < available.size(); index++) {
            // try use the person
            auto skill = people[index];

            // remove skills
            int left_skills = needSkills;
            // record skill
            vector<bool> removed_skills;
            for (auto s : skill) {
                if (skills[s]) {
                    left_skills--;
                    skills[s] = false;
                    removed_skills.push_back(s);
                }
            }

            // remove available
            available[index] = false;

            // rec
            auto recResult = rec(skills, available, left_skills, people);

            if (recResult.size() < minResult) {
                minResult = recResult.size();
                minIndex = index;
                minList = recResult;
            }

            // add back skills
            available[index] = true;
            for (auto s : removed_skills) {
                skills[s] = true;
            }
        }
        minResult++;
        minList.insert(minIndex);

        return minList;
    }
};