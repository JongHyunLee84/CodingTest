import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var array = number.map { Int(String($0))! }
    var ret: [Int] = [array.first!]
    var cnt = 0
    for i in 1..<array.count {
        while true {
            if ret.isEmpty {
                ret.append(array[i])
                break
            } else if ret.last! < array[i] && cnt < k {
                ret.removeLast()
                cnt += 1
            } else {
                ret.append(array[i])
                break
            }
        }
    }
    if cnt != k {
        for _ in 0..<k-cnt {
            ret.removeLast()
        }
    }
    return ret.map { String($0) }.joined()
    
}