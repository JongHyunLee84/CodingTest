import Foundation

func solution(_ bin1:String, _ bin2:String) -> String {
    var num1 = Int(bin1, radix: 2)!
    var num2 = Int(bin2, radix: 2)!
    return String(num1+num2, radix: 2)
}