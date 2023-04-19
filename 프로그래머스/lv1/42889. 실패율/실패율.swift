import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    // 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
    var sum: [Int] = Array(repeating: 0, count: N+2)
    for i in stages {
        sum[i] += 1
    }
    var fail: [(Int, Double)] = []
    for i in 1...N {
        var a = sum[i...N+1]
        var b = sum[i]
        var c = a.reduce(0, +)
        if  b == 0 ||  c == 0 {
            fail.append((i,0))
            continue
        }
        let proportion = Double(b) / Double(c)
        fail.append((i,proportion))
    }
    var result: [Int] = [fail[0].0]
    for i in 1..<N {
        var index = 0
        for j in 0..<result.count {
            if fail[i].1 <= fail[result[j]-1].1 {
                index += 1
            } else {
                break
            }
        }
        result.insert(i+1, at: index)
    }
    return result
}