import Foundation
func solution(_ s:String) -> String {
    var array = s.components(separatedBy: " ")
    var result : [String] = []
    for i in array {
        var str = ""
        for j in 0..<i.count {
            if j == 0 {
                str += String(Array(i)[j]).uppercased()
                continue
            } else if j % 2 == 0 {
                str += String(Array(i)[j]).uppercased()
            } else {
                str += String(Array(i)[j]).lowercased()
            }
        }
        result.append(str)
    }
    return result.joined(separator: " ")
}