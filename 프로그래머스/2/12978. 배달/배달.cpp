#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int destination;
    int cost;
};

vector<int> dijkstra(int N, vector<vector<Edge>>& graph, int start) {
    vector<int> dist(N + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curDist > dist[curNode]) continue;

        for (const auto& edge : graph[curNode]) {
            int nextNode = edge.destination;
            int newDist = curDist + edge.cost;

            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    return dist;
}

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<Edge>> graph(N + 1);

    for (const auto& r : road) {
        int a = r[0], b = r[1], c = r[2];
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<int> dist = dijkstra(N, graph, 1);

    // K 이하로 배달 가능한 마을 수 카운트
    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] <= K) {
            answer++;
        }
    }

    return answer;
}