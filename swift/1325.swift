import Foundation

func readInput() -> (Int, Int, [(Int, Int)]) {
    let nm = readLine()!.split(separator: " ").map { Int($0)! }
    let n = nm[0]
    let m = nm[1]
    var trustRelations: [(Int, Int)] = []
    
    for _ in 0..<m {
        let relation = readLine()!.split(separator: " ").map { Int($0)! }
        trustRelations.append((relation[0], relation[1]))
    }
    
    return (n, m, trustRelations)
}

func dfs(_ node: Int, _ graph: [[Int]], _ visited: inout [Bool]) -> Int {
    var stack: [Int] = [node]
    visited[node] = true
    var count = 1
    
    while !stack.isEmpty {
        let current = stack.removeLast()
        
        for next in graph[current] {
            if !visited[next] {
                visited[next] = true
                count += 1
                stack.append(next)
            }
        }
    }
    
    return count
}

func solution() {
    let (n, _, trustRelations) = readInput()
    
    var graph = [[Int]](repeating: [], count: n + 1)
    
    for (a, b) in trustRelations {
        graph[b].append(a)  
    }
    
    var maxHackCount = 0
    var result: [Int] = []
    
    for i in 1...n {
        var visited = [Bool](repeating: false, count: n + 1)
        let hackCount = dfs(i, graph, &visited)
        
        if hackCount > maxHackCount {
            maxHackCount = hackCount
            result = [i]  
        } else if hackCount == maxHackCount {
            result.append(i)  
        }
    }
    
    print(result.sorted().map { String($0) }.joined(separator: " "))
}

solution()
