#include <bits/stdc++.h>

using namespace std;

typedef long long bigNumber;

class Graph {
    bigNumber vertex;
    list<bigNumber> *newNode;
public:
    explicit Graph(bigNumber vertex) {
        this->vertex = vertex;
        this->newNode = new list<bigNumber>[vertex];
    }

    void addEdge(bigNumber i, bigNumber j, bool undirected = true) const {
        newNode[i].push_back(j);
        if (undirected) newNode[j].push_back(i);
    }

    bool
    modifiedBFS(bigNumber source, bigNumber destination, vector<bigNumber> &predecessor,
                vector<bigNumber> &distance) const {
        queue<bigNumber> q;

        vector<bool> visited(vertex, false);

        visited.at(source) = true;
        distance.at(source) = 0;
        q.push(source);

        while (!q.empty()) {
            bigNumber temp = q.front();
            q.pop();

            for (auto node: newNode[temp]) {
                if (!visited.at(node)) {
                    visited.at(node) = true;
                    distance.at(node) = distance.at(temp) + 1;
                    predecessor.at(node) = temp;
                    q.push(node);

                    if (node == destination) {
                        return true;
                    }
                }
            }

        }

        return false;
    }

    [[nodiscard]] vector<bigNumber> findShortestDistance(bigNumber source, bigNumber destination) const {

        vector<bigNumber> predecessor(vertex, INT_MIN), distance(vertex, INT_MAX), path, output;

        bigNumber traverse{destination};

        if (!modifiedBFS(source, destination, predecessor, distance)) {
            return output;
        }

        path.push_back(traverse);

        while (predecessor.at(traverse) != INT_MIN) {
            path.push_back(predecessor.at(traverse));
            traverse = predecessor.at(traverse);
        }

        for (auto i = path.size(); i > 0; i--) {
            output.push_back(path.at(i - 1));
        }

        return output;
    }
};

int main() {
    bigNumber numberOfFileTypes, numberOfPossibleConversions, startIndex, desiredIndex;

    string fromFileType, toFileType, startingFileType, desiredFileType, temp;

    vector<bigNumber> numericalAnswerSet;
    cin >> numberOfFileTypes;

    map<string, bigNumber> fileTypes;

    for (bigNumber i{0}; i < numberOfFileTypes; i++) {
        cin >> temp;
        fileTypes.insert({temp, i});
    }

    cin >> numberOfPossibleConversions;
    Graph possibleConversions(numberOfPossibleConversions);

    for (bigNumber i{0}; i < numberOfPossibleConversions; i++) {
        cin >> fromFileType >> toFileType;
        possibleConversions.addEdge(fileTypes.find(fromFileType)->second, fileTypes.find(toFileType)->second, false);
    }

    cin >> startingFileType >> desiredFileType;

    startIndex = fileTypes.find(startingFileType)->second;
    desiredIndex = fileTypes.find(desiredFileType)->second;

    numericalAnswerSet = possibleConversions.findShortestDistance(startIndex, desiredIndex);

    if (!numericalAnswerSet.empty()) {
        for (auto node: numericalAnswerSet) {
            for (auto &iterator: fileTypes) {
                if (iterator.second == node) {
                    cout << (iterator.first) << " ";
                }
            }
        }
    } else {
        cout << "Not Possible";
    }

    return 0;
}