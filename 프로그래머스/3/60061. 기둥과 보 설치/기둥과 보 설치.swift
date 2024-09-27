import Foundation

struct Frame: Equatable {
    let x: Int
    let y: Int
    let type: Int // 0: 기둥, 1: 보
}

func canBuildPillar(_ x: Int, _ y: Int, _ structure: [Frame]) -> Bool {
    // 바닥이거나 보의 한쪽 끝 위에 있거나 다른 기둥 위에 있는 경우
    return y == 0 || 
           structure.contains(where: { $0.x == x && $0.y == y && $0.type == 1 }) ||
           structure.contains(where: { $0.x == x-1 && $0.y == y && $0.type == 1 }) ||
           structure.contains(where: { $0.x == x && $0.y == y-1 && $0.type == 0 })
}

func canBuildBeam(_ x: Int, _ y: Int, _ structure: [Frame]) -> Bool {
    // 한쪽 끝 부분이 기둥 위에 있거나 양쪽 끝 부분이 다른 보와 동시에 연결된 경우
    return structure.contains(where: { $0.x == x && $0.y == y-1 && $0.type == 0 }) ||
           structure.contains(where: { $0.x == x+1 && $0.y == y-1 && $0.type == 0 }) ||
           (structure.contains(where: { $0.x == x-1 && $0.y == y && $0.type == 1 }) &&
            structure.contains(where: { $0.x == x+1 && $0.y == y && $0.type == 1 }))
}

func canDelete(_ frame: Frame, _ structure: [Frame]) -> Bool {
    let tempStructure = structure.filter { $0 != frame }
    return tempStructure.allSatisfy { f in
        if f.type == 0 {
            return canBuildPillar(f.x, f.y, tempStructure)
        } else {
            return canBuildBeam(f.x, f.y, tempStructure)
        }
    }
}

func solution(_ n: Int, _ build_frame: [[Int]]) -> [[Int]] {
    var structure: [Frame] = []
    
    for frame in build_frame {
        let x = frame[0]
        let y = frame[1]
        let a = frame[2]
        let b = frame[3]
        
        if b == 1 { // 설치
            if a == 0 { // 기둥
                if canBuildPillar(x, y, structure) {
                    structure.append(Frame(x: x, y: y, type: a))
                }
            } else { // 보
                if canBuildBeam(x, y, structure) {
                    structure.append(Frame(x: x, y: y, type: a))
                }
            }
        } else { // 삭제
            let frameToDelete = Frame(x: x, y: y, type: a)
            if canDelete(frameToDelete, structure) {
                structure.removeAll { $0 == frameToDelete }
            }
        }
    }
    
    return structure.sorted { 
        if $0.x != $1.x {
            return $0.x < $1.x
        } else if $0.y != $1.y {
            return $0.y < $1.y
        } else {
            return $0.type < $1.type
        }
    }.map { [$0.x, $0.y, $0.type] }
}