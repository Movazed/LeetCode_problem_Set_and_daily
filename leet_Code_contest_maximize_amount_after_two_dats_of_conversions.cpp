#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;

#define FOR(i, start, end) for (ll i = start; i < end; ++i)
#define REP(i, end) FOR(i, 0, end)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define UPDATE_GRAPH(graph, i, j, k) graph[i][j] = MAX(graph[i][j], graph[i][k]*graph[k][j])
#define GET_CURRENCY_INDEX(currency, index, currencyIndex) \
    if(currencyIndex.find( currency)==currencyIndex.end()) { currencyIndex[currency]=index++; }

template<typename T>
void populateGraph(std::vector<std::vector<T>>& graph, const std::vector<std::vector<std::string>>& pairs, const std::vector<T>& rates, std::unordered_map<std::string, ll>& currencyIndex) {
    REP(i, pairs.size()) {
        ll u = currencyIndex[pairs[i][0]];
        ll v = currencyIndex[pairs[i][1]];
        
        std::vector<std::pair<ll, ll>> edges = {{u, v}, {v, u}};
        std::vector<T> values = {rates[i], 1.0 / rates[i]};

        REP(j, edges.size()) {
            ll from = edges[j].first;
            ll to = edges[j].second;
            graph[from][to] = values[j];
        }
    }
}

template<typename T>
void initializeGraph(std::vector<std::vector<T>>& graph, ll n) {
    graph.assign(n, std::vector<T>(n, 0.0));
    REP(i, n) {
        graph[i][i] = 1.0;
    }
}

class Solution {
 public:
    void floydWarshall(std::vector<std::vector<double>>& graph) {
        ll n = graph.size();
        ll k = 0;
        while (k < n) {
            ll i = 0;
            while (i < n) {
                ll j = 0;
                while (j < n) {
                    UPDATE_GRAPH(graph, i, j, k);
                    ++j;
                }
                ++i;
            }
            ++k;
        }}

    double maxAmount(std::string initialCurrency, std::vector<std::vector<std::string>>& pairs1, std::vector<double>& rates1, std::vector<std::vector<std::string>>& pairs2, std::vector<double>& rates2) {
        std::unordered_map<std::string, ll> currencyIndex;
        ll index = 0;
        REP(i, pairs1.size()) {
            GET_CURRENCY_INDEX(pairs1[i][0], index, currencyIndex);
            GET_CURRENCY_INDEX(pairs1[i][1], index, currencyIndex);
        }
        
        REP(j, pairs2.size()) {
            GET_CURRENCY_INDEX(pairs2[j][0], index, currencyIndex);
            GET_CURRENCY_INDEX(pairs2[j][1], index, currencyIndex);
        }

        ll n=currencyIndex.size();

        std::vector<std::vector<double>> graph1, graph2;


        initializeGraph(graph1, n);
        initializeGraph(graph2, n);


        populateGraph(graph1, pairs1, rates1, currencyIndex);
        populateGraph(graph2, pairs2, rates2, currencyIndex);

        floydWarshall(graph1 ); 
        floydWarshall(graph2 );
        ll startIdx=currencyIndex[ initialCurrency ];

        std::vector<double>maxDay1(n, 0.0);
        ll k = 0;
        while (k < n) {
            maxDay1[k] = graph1[startIdx][k];
            ++k;
        }

        double maxAmount =1.0;
        ll m = 0;
        while (m < n) {
            maxAmount = MAX(maxAmount, maxDay1[m] * graph2[m][startIdx]);
            ++m;
        }

        return maxAmount;
    }
};