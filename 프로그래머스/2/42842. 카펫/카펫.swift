import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    let divisorArray = make(yellow)
    // print(divisorArray)
    for i in divisorArray {
        let height = yellow / i
        if height > i { continue }
        if ((i+2)*2) + (((height+2)*2)-4) == brown {
            return [i+2, height+2]
        }
    }
    return []
}

func make(_ num: Int) -> [Int] {
    var temp: [Int] = []
    for i in 1...num {
        if num % i == 0 { temp.append(i)}
    }
    return temp
}