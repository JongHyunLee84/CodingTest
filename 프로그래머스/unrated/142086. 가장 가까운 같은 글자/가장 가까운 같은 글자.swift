import Foundation

func solution(_ s:String) -> [Int] {
    var result: [Int] = []
    for (index, chr) in s.enumerated() {
        if index == 0 {
            result.append(-1)
            continue
        }
        var willAdded = -1
        var a = s.index(s.startIndex, offsetBy: index)
        var b = Array(String(s[s.startIndex..<a]))
        if b.contains(chr) {
            willAdded = index - Int(b.lastIndex(of: chr)!)
        }
        result.append(willAdded)
    }
    return result
}
