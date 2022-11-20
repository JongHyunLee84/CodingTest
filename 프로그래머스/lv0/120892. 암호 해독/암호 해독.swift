import Foundation

func solution(_ cipher:String, _ code:Int) -> String {
    var array = Array(cipher)
    var result : [Character] = []
    for i in 1...array.count {
        if i % code == 0 {
            result.append(array[i-1])
        }
    }
    return String(result)
}