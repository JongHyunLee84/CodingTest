import Foundation

func solution(_ numbers:String) -> Int64 {
    var str = ""
    var result = ""
    var check = false
    for i in numbers {
        str += String(i)
        switch str {
            case "zero":
            result += "0"
            check = true
            case "one":
            result += "1"
            check = true
            case "two":
            result += "2"
            check = true
            case "three":
            result += "3"
            check = true
            case "four":
            result += "4"
            check = true
            case "five":
            result += "5"
            check = true
            case "six":
            result += "6"
            check = true
            case "seven":
            result += "7"
            check = true
            case "eight":
            result += "8"
            check = true
            case "nine":
            result += "9"
            check = true
            default:
            break
        }
        if check {
            check = false 
            str = ""
        }
    }
    return Int64(result)!
}