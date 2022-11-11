import Foundation

func solution(_ n:Int) -> Int {
    //피자 한 판에 7 조각
    
    var pizza = n / 7
    if n % 7 > 0  {
        pizza += 1
    }
    // n명이 한 조각 '이상' 먹기 위한 피자 판 수
    return pizza
}