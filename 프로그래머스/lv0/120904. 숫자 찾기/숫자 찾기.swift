import Foundation

func solution(_ num:Int, _ k:Int) -> Int {
    var n = Array(String(num))
    var strK = Character(String(k))
    var result = 0 
    for i in n {
        if i == strK {
            result = n.firstIndex(of: strK)! + 1
            break
        } else {
            result = -1        }
    }
    return result
}