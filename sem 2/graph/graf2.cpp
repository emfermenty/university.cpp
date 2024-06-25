#include "pt4.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void Solve()
{
    Task("Graf2");
    string input;
    string output;
    GetS(input);
    GetS(output);
    fstream file(input);
    int n;
    file >> n;

    vector <vector<int>> smez(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> smez[i][j];
        }
    }
    file.close();
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (smez[i][j] != 0) {
                m++;
            }
        }
    }
    vector<vector<int>> inds(n, vector<int>(m));
    int edgeIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (smez[i][j] != 0) {
                inds[i][edgeIndex] = 1;
                inds[j][edgeIndex] = 1;
                edgeIndex++;
            }
        }
    }
    ofstream out(output);
    out << n << " " << m << endl;
    if (n != 0) {
        for (int i = 0; i < n; i++) {
            if (m != 0) {
                out << " ";
                for (int j = 0; j < m; j++) {
                    out << "  " << inds[i][j];
                }
            }
            out << endl;
        }
    }
}
