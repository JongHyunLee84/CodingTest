import Foundation

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int
{
    var aa = a
    var bb = b
    var ret = 0
    while aa ^ 1 != bb ^ 1 {
        ret += 1
        if aa % 2 == 0 {
            aa /= 2
        } else {
            aa = (aa + 1) / 2
        }
        if bb % 2 == 0 {
            bb /= 2
        } else {
            bb = (bb + 1) / 2
        }
    }
    return ret
}