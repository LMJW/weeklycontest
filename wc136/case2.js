/**
 * @param {number} N
 * @param {number[][]} paths
 * @return {number[]}
 */
var gardenNoAdj = function (N, paths) {
    let conn = {}
    paths.forEach(p => {
        let e1 = p[0];
        let e2 = p[1];
        if (conn[e1] === undefined) {
            conn[e1] = new Set([e2])
        } else {
            conn[e1].add(e2);
        }
    })

    let color = {}
    const assign = key => {
        let nei = conn[key];
        let nei_color = new Set(nei.forEach(e => (color[e])))
        for (var i = 1; i <= N; i++) {
            if (nei_color.has(i)) {
                continue;
            }
            color[key] = i;
            break;
        }
    }
    Object.keys(conn).map(assign)

    var res = []
    for (let j = 1; j <= Object.keys(conn).length; j++) {
        res.push(color[j])
    }
    return res;
};