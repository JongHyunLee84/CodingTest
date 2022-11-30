import Foundation

func solution(_ s:String) -> Int {
    var array = s.components(separatedBy: " ")
    var result = 0
    var minus = 1
if array[0] == "Z" {
    array.remove(at: 0)
}
    for i in 0..<array.count {
        if let a = Int(array[i]) {
            result += a
        } else if array[i] == "Z" {
            while Int(array[i-minus]) == nil {
                minus += 2
            }
            result -= Int(array[i-minus])!
            minus = 1
        }
        
    }
    return result
}
