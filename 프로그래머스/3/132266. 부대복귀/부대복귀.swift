import Foundation

func solution(_ n:Int, _ roads:[[Int]], _ sources:[Int], _ destination:Int) -> [Int] {
    // des로 시작해서 연결된 부분을 추가하며 거리를 1씩 늘린다.
    // 초기화는 max로 해서 만약 부대원 위치가 max라면 -1을 리턴
    // 최단 거리가 이미 있다면 다음 추가 배열에 추가하지 않는다. 
    var arr = Array(repeating: Int.max, count: n+1)
    var connect: [Int: [Int]] = [:]
    for i in roads {
        connect[i[0], default: []].append(i[1])
        connect[i[1], default: []].append(i[0])
    }
    // for i in connect.keys.sorted() {
    //     print(i)
    //     for j in connect[i, default: []] {
    //         print(j, terminator: " ")
    //     }
    //     print("")
    // }
    var temp: [Int] = []
    var tempNum = 0
    temp = connect[destination, default: []]
    arr[destination] = 0
    while(!temp.isEmpty) {
        var ttemp: [Int] = []
        for i in temp {
            if arr[i] > tempNum {
                arr[i] = tempNum + 1
                ttemp += connect[i, default: []]
            }
        }
        temp = ttemp
        tempNum += 1
    }
    var result: [Int] = sources.map { 
        if arr[$0] == .max { return -1 }
        else { return arr[$0] }
    }
    return result
}