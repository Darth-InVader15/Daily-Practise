import heapq

class Solution:
    def maxProbability(self, n, edges, succProb, start, end):
        # Create the adjacency list
        adj = [[] for _ in range(n)]
        
        for i in range(len(edges)):
            adj[edges[i][0]].append((edges[i][1], succProb[i]))
            adj[edges[i][1]].append((edges[i][0], succProb[i]))

        # Array to store the highest probability to reach each node
        probs = [0.0] * n
        probs[start] = 1.0

        # Priority queue (max-heap simulation using negative probabilities)
        pq = [(-1.0, start)]
        heapq.heapify(pq)

        while pq:
            prob, node = heapq.heappop(pq)
            prob = -prob  # Convert back to positive probability

            if node == end:
                return prob

            if probs[node] > prob:
                continue

            for next_node, next_prob in adj[node]:
                curr = prob * next_prob
                if curr > probs[next_node]:
                    probs[next_node] = curr
                    heapq.heappush(pq, (-curr, next_node))  # Push negative for max-heap simulation

        return 0.0

# # Example usage:
# solution = Solution()
# n = 3
# edges = [[0, 1], [1, 2], [0, 2]]
# succProb = [0.5, 0.5, 0.2]
# start = 0
# end = 2
# print(solution.maxProbability(n, edges, succProb, start, end))  # Output: 0.25
