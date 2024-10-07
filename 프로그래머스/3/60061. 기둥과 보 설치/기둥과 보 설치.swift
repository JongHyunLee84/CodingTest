import Foundation

var column = [[Int]]()
var beam = column
var nn = -1
func solution(_ n:Int, _ build_frame:[[Int]]) -> [[Int]] {
    // 조건에 만족하지 않으면 설치 or 삭제 x
    // 기둥 : 0 보 : 1
    // 설치 : 1 삭제 : 0
    nn = n
    column = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)
    beam = column
    for i in build_frame {
        let x = i[0]
        let y = i[1]
        let isColumn = i[2] == 0 ? true : false
        let isInstall = i[3] == 0 ? false : true
        if isColumn && isInstall && columnInstall(y, x) { column[y][x] = 1 }
        else if isColumn && !isInstall && columnDelete(y, x) { column[y][x] = 0 }
        else if !isColumn && isInstall && beamInstall(y, x) { beam[y][x] = 1 }
        else if !isColumn && !isInstall && beamDelete(y, x) { beam[y][x] = 0 }
    }
    var result: [Custom] = []
    for i in 0...n {
        for j in 0...n {
            if column[i][j] == 1 { result.append(.init(y: i, x: j, isColumn: 0)) }
            if beam[i][j] == 1 { result.append(.init(y: i, x: j, isColumn: 1)) }
        }
    }
    return result.sorted {
        if $0.x == $1.x {
            if $0.y == $1.y {
                return $0.isColumn == 0
            }
            return $0.y < $1.y
        }
        return $0.x < $1.x
    }.map { return [$0.x, $0.y, $0.isColumn] }
}

struct Custom {
    let y, x, isColumn: Int
}

// 기둥 설치 조건 : 바닥 or 보 위에 or 다른 기둥 위
func columnInstall(_ y: Int, _ x: Int) -> Bool {
    // 바닥
    if y == 0 { return true }
    // 다른 기둥 위
    if y - 1 >= 0, column[y-1][x] == 1 { return true }
    // 보 위에
    if beam[y][x] == 1 { return true }
    if x - 1 >= 0, beam[y][x-1] == 1 { return true }
    return false
}
// 기둥 삭제 조건 : (다른 보에 걸쳐지지 않은 기둥 아래 x) & (위에 올라간 보(들)이 있다면 양옆에 다른 보가 있음 or 해당 보의 반대쪽에 기둥이 있음.)
func columnDelete(_ y: Int, _ x: Int) -> Bool {
    // 바로 위에 다른 보에 걸쳐지지 않은 기둥 존재하면 x
    if y + 1 <= nn, column[y+1][x] == 1 {
        var temp = 0
        if x - 1 >= 0, beam[y+1][x-1] == 1 { temp += 1 }
        if beam[y+1][x] == 1 { temp += 1 }
        if temp == 0 { return false }
    }
    // 해당 기둥 바로 위에 보가 있고,
    if beam[y+1][x] == 1 {
        var temp = 0
        // 양옆에 다른 보가 있음.
        if x - 1 >= 0, x + 1 <= nn, beam[y+1][x-1] == 1 && beam[y+1][x+1] == 1 { temp += 1 }
        // 위에 보의 오른쪽에 기둥이 있음.
        if x + 1 <= nn, column[y][x+1] == 1 { temp += 1 }
        if temp == 0 { return false }
    }
    // 해당 기둥 왼쪽에 보가 있고,
    if x - 1 >= 0, beam[y+1][x-1] == 1 {
        var temp = 0
        // 왼쪽 보의 바로 아래에 기둥이 있음.
        if column[y][x-1] == 1 { temp += 1 }
        // 왼쪽 보의 양 옆에 보가 있음.
        if x - 2 >= 0, beam[y+1][x-2] == 1 && beam[y+1][x] == 1 { temp += 1 }
        if temp == 0 { return false }
    }
    return true
}
// 보 설치 조건 : 기둥 위 or 양쪽이 다른 보와 연결
func beamInstall(_ y: Int, _ x: Int) -> Bool {
    // 바로 아래에 기둥이 존재
    if y - 1 >= 0, column[y-1][x] == 1 { return true }
    // 보의 오른쪽 아래에 기둥이 존재
    if x + 1 <= nn, y - 1 >= 0, column[y-1][x+1] == 1 { return true }
    // 양쪽이 다른 보와 연결
    if x - 1 >= 0, x + 1 <= nn, beam[y][x-1] == 1 && beam[y][x+1] == 1 { return true }
    return false
}

    // 보 : 한쪽 끝 부분이 기둥 위에 있거나 양쪽 끝 부분이 다른 보와 동시에 연결된 경우
    // 기둥 : 바닥이거나 보의 한쪽 끝 위에 있거나 다른 기둥 위에 있는 경우

// 보 삭제 조건 : 양옆 연결된 보들 각각 기둥이 있음 & (위로 올라간 기둥이 있다면 내가 아니어도 다른 보가 지탱 가능)
func beamDelete(_ y: Int, _ x: Int) -> Bool {
    // 바로 위로 올라간 기둥이 있다면 내가 아니어도 왼쪽 보가 지탱 가능 또는 아래에 기둥이 있음.
    if column[y][x] == 1 {
        var temp = 0
        if x - 1 >= 0, beam[y][x-1] == 1 { temp += 1 }
        if y - 1 >= 0, column[y-1][x] == 1 { temp += 1 }
        if temp == 0 { return false }
    }
    // 오른쪽 위로 올라간 기둥이 있다면, 내가 아니어도 해당 위치의 보가 지탱 가능 또는 아래에 기둥이 있음.
    if x + 1 <= nn, column[y][x+1] == 1 {
        var temp = 0
        if beam[y][x+1] == 1 { temp += 1 }
        if y - 1 >= 0, column[y-1][x+1] == 1 { temp += 1 }
        if temp == 0 { return false }
    }
    // 왼쪽 보 있다면, 보 아래로 지탱 가능한 기둥들이 있음.
    if x - 1 >= 0, beam[y][x-1] == 1 {
        var temp = 0
        if y - 1 >= 0, column[y-1][x-1] == 1 { temp += 1 }
        if y - 1 >= 0, column[y-1][x] == 1 { temp += 1 }
        if temp == 0 { return false }
    }
    // 오른쪽 보 있다면, 보 아래로 지탱 가능한 기둥들이 있음.
    if x + 1 <= nn, beam[y][x+1] == 1 {
        var temp = 0
        if y - 1 >= 0, column[y-1][x+1] == 1 { temp += 1 }
        if y - 1 >= 0, x + 2 <= nn, column[y-1][x+2] == 1 { temp += 1 }
        if temp == 0 { return false }
    }
    return true
}
