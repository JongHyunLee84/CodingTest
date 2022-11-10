import Foundation

func solution(_ numbers:[Int]) -> Double {
    var sum: Double = 0
    var average: Double = 0
    for i in numbers {
        
        sum += Double(i)
    }
    // var a = sum / numbers.count
    // var b = sum % numbers.count
    average = sum/Double(numbers.count)
    
    return average
}