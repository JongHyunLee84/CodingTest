import Foundation

func solution(_ my_string:String) -> Int {
    var result = 0 
    var str = "0"
    var array = Array<Int>()
    for i in my_string {
        if i.isNumber {
            str += String(i)
        } else {
            array.append(Int(str)!)
            str = "0"
        }
    }
    array.append(Int(str)!)
    for i in array {
        result += i
    }
    return result
}