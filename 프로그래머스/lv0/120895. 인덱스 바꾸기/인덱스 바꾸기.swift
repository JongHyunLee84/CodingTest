import Foundation

func solution(_ my_string:String, _ num1:Int, _ num2:Int) -> String {
    var array = Array(my_string)
    var result : [Character] = []
    for i in 0..<my_string.count {
if i == num1 {
    result.append(array[num2])
} else if i == num2 {
    result.append(array[num1])
} else {
    result.append(array[i])
}
    }
    return String(result)
}