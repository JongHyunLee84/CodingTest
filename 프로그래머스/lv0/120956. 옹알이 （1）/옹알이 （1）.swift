import Foundation

func solution(_ babbling:[String]) -> Int {
    var result = 0
    for i in babbling {
        var k = i
        if k.contains("aya") {
            k = k.replacingOccurrences(of: "aya", with: " ")
        }
        if k.contains("ye") {
            k = k.replacingOccurrences(of: "ye", with: " ")
        }
        if k.contains("woo") {
           k = k.replacingOccurrences(of: "woo", with: " ")
        }
        if k.contains("ma") {
            k = k.replacingOccurrences(of: "ma", with: " ")
        }
        k = k.replacingOccurrences(of: " ", with: "")
        if k.isEmpty {
            result += 1
        }
    
    }
    return result
}