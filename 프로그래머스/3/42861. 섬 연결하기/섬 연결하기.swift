import Foundation

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var sortedCost = costs
    sortedCost.sort { $0[2] < $1[2] }
    var cnt = 0 
    var ret = 0
    var nodes = Array(0..<n)
    func findParent(_ x: Int) -> Int {
        if nodes[x] == x {
            return x
        } else {
            return findParent(nodes[x])
        }
    }
    for i in sortedCost {
        if findParent(nodes[i[0]]) == findParent(nodes[i[1]]) {
            //
        } else {
            if findParent(nodes[i[0]]) > findParent(nodes[i[1]]) {
                let shouldChange = nodes[i[0]]
                let value = findParent(nodes[i[1]])
                for i in 0..<nodes.count {
                    if nodes[i] == shouldChange {
                        nodes[i] = value
                    }
                }
                 
            } else {
                let shouldChange = nodes[i[1]]
                let value = findParent(nodes[i[0]])
                for j in 0..<nodes.count {
                    if nodes[j] == shouldChange {
                        nodes[j] = value
                    }
                }
            }
            ret += i[2]
        }
        // print(nodes, ret)
        // a와 b를 연결했을 때 사이클 여부 확인 (부모가 같은지)
        // a와 b를 연결시킨다(union). cnt ++, ret += 비용
        // else continue
    }
    return ret
}