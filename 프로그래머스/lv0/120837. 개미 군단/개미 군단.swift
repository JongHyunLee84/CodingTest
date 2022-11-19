import Foundation

func solution(_ hp:Int) -> Int {
    var general = hp / 5
    var soldier = (hp % 5) / 3
    var worker = ((hp % 5) % 3) / 1
    return general + soldier + worker
}