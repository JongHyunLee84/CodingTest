import Foundation

func solution(_ box:[Int], _ n:Int) -> Int {
    var w = box[0] / n
    var d = box[1] / n 
    var h = box[2] / n 
    return w * d * h
}