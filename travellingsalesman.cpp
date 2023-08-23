
#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
int calculateLowerBound(vector<vector<int>>& graph, vector<bool>& visited, int currNode) 
{
int lowerBound = 0;
int minEdge = INF;
for (int i = 0; i < graph.size(); ++i) {
if (!visited[i] && graph[currNode][i] < minEdge) {
minEdge = graph[currNode][i];
} }
lowerBound += minEdge;
vector<int> minEdges(graph.size(), INF);
for (int i = 0; i < graph.size(); ++i) {
if (!visited[i]) {
for (int j = 0; j < graph.size(); ++j) {
if (graph[i][j] < minEdges[i] && i != j) {
minEdges[i] = graph[i][j];
}}
lowerBound += minEdges[i];
}}
return lowerBound;
}
void tspBranchAndBound(vector<vector<int>>& graph, vector<bool>& visited, int currNode, int currCost, int& minCost) {
if (visited.size() == graph.size()) {
minCost = min(minCost, currCost + graph[currNode][0]); 
return;

}
for (int i = 0; i < graph.size(); ++i) {
if (!visited[i]) {
int lowerBound = calculateLowerBound(graph, visited, currNode);
if (currCost + graph[currNode][i] + lowerBound < minCost) {
visited[i] = true;
tspBranchAndBound(graph, visited, i, currCost + graph[currNode][i], minCost);
visited[i] = false;
}}}}
int main() 
{
int n;
cout<<"Enter the value of n"<<endl;
cin >> n;
vector<vector<int>> graph(n, vector<int>(n));
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
cin >> graph[i][j];
}}
vector<bool> visited(n, false);
visited[0] = true; 
int minCost = INF;
tspBranchAndBound(graph, visited, 0, 0, minCost);
cout << "Minimum TSP cost: " << minCost << endl;
return 0;
}