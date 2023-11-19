import Foundation

func solution(_ n:Int, _ results:[[Int]]) -> Int {
    var stronger: [[Int]] = Array(repeating: [], count: n+1)
    var weaker: [[Int]] = Array(repeating: [], count: n+1)
    var ret = 0
    for i in results {
        weaker[i[0]].append(i[1])
        stronger[i[1]].append(i[0])
    }
    
    func strongerDfs(_ num: Int, _ next: Int) {
        for i in stronger[next] {
            if stronger[num].contains(i) {
                continue
            } else {
                stronger[num].append(i)
                strongerDfs(num, i)
            }
        }
    }
    func weakerDfs(_ num: Int, _ next: Int) {
        for i in weaker[next] {
            if weaker[num].contains(i) {
                continue
            } else {
                weaker[num].append(i)
                weakerDfs(num, i)
            }
        }
    }

    for i in 1...n {
        for j in stronger[i] {
            strongerDfs(i,j)
        }
        for j in weaker[i] {
            weakerDfs(i,j)
        }
    }
    for i in 1...n {
        if stronger[i].count + weaker[i].count == n - 1{
            ret += 1
        }
    }
    return ret
}