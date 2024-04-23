import Foundation

func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
    var y = board.count
    var x = board[0].count
    var array = Array(repeating: Array(repeating: 0, count: x+1), count: y+1)
    for i in skill {
        let type = i[0]
        let y1 = i[1]
        let x1 = i[2]
        let y2 = i[3]
        let x2 = i[4]
        let degree = i[5]
        if type == 1 { // 공격
            array[y1][x1] -= degree
            array[y1][x2+1] += degree
            array[y2+1][x1] += degree
            array[y2+1][x2+1] -= degree
        } else {
            array[y1][x1] += degree
            array[y1][x2+1] -= degree
            array[y2+1][x1] -= degree
            array[y2+1][x2+1] += degree
        }
    }
    // 좌우 누적
    for i in 0...y {
        var sum = 0
        for j in 0...x {
            let temp = array[i][j]
            sum += temp
            array[i][j] = sum
        }
    }
    // 상하 누적
    for i in 0...x {
        var sum = 0
        for j in 0...y {
            let temp = array[j][i]
            sum += temp
            array[j][i] = sum
        }
    }
    var result = 0
    for i in 0..<y {
        for j in 0..<x {
            if(board[i][j] + array[i][j] > 0) {
                result += 1
            }
        }
    }
    return result
}
func pp(_ y: Int, _ x: Int, _ array: [[Int]]) {
// 체크
for i in 0...y {
    for j in 0...x {
        print(array[i][j], terminator: " ")
    }
    print("")
}
print("")
}