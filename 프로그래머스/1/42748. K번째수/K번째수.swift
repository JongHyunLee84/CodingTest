import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var result: [Int] = []
    for i in 0..<commands.count {
        var temp: [Int] = Array(array[commands[i][0]-1..<commands[i][1]])
        
        var sorted = temp.sorted()
        result.append(sorted[commands[i][2]-1])
    }
    return result
}