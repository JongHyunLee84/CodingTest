import Foundation

func solution(_ food:[Int]) -> String {
    var array = food.map { $0 / 2 }
    var result = ""
    array.enumerated().forEach { (index, food) in
        if food != 0 {
            result += String(repeating: "\(index)", count: food)
        }
    }
    return result + "0" + result.reversed()
}