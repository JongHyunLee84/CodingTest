import Foundation
func solution(_ info:[Int], _ edges:[[Int]]) -> Int {
    // 아직 방문하지 않아서 방문 가능한 모든 노드를 한번씩 재귀적으로 방문
    // 양보다 늑대가 많아지면 종료, 방문 취소 후 원복
    // 매번 양의 수를 max와 비교 
    // max값 리턴
    var maxSheep = 0
    var nodes = Array(repeating: Node(), count: info.count)
    for i in edges {
        nodes[i[0]].childs.append(i[1])
    }
    func trace(_ current: Int, _ sheep: Int, _ wolf: Int, _ path: [Int]) {
        var nextSheep = sheep
        var nextWolf = wolf
        var nextPath = path
        if info[current] == 0 { nextSheep += 1 }
        else { nextWolf += 1 }
        maxSheep = max(maxSheep, nextSheep)
        if nextSheep <= nextWolf { return }
        nextPath.append(contentsOf: nodes[current].childs)
        for i in nextPath {
            trace(i, nextSheep, nextWolf, nextPath.filter { $0 != i})
        }
    }
    trace(0, 0, 0, [])
    return maxSheep
}



struct Node {
    var childs: [Int] = []
}