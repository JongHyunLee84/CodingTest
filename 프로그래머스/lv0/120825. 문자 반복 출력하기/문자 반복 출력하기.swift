import Foundation

func solution(_ my_string:String, _ n:Int) -> String {
    var strArray = Array(my_string)
    var result = strArray.map { String(repeating: $0, count: n)
    }
    return result.joined()
}