import Foundation

func solution(_ my_string:String)-> Int {
    var string = my_string.filter { $0.isNumber }
    var array = Array(string)
    var result: Int = 0
    for i in array {
        result += Int(String(i))!
    }
    return result
}