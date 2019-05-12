/**
 * @param {string} instructions
 * @return {boolean}
 */
var isRobotBounded = function (instructions) {
    instructions.repeat(4)
    let x = 0;
    let y = 0;
    let dir = 0; // 0:north 1:east 2:south 3 west

    const move = () => {
        if (dir === 0) {
            y++;
        } else if (dir === 1) {
            x++;
        } else if (dir === 2) {
            y--;
        } else {
            x--;
        }
    }

    const turn = (d) => {
        if (d === 'L') {
            dir = (dir - 1 + 4) % 4;
        } else {
            dir = (dir + 1) % 4;
        }
    }

    instructions.map((cmd) => {
        if (cmd === 'G') {
            move()
        } else {
            turn(cmd)
        }
    })

    return (x === 0 && y === 0 && dir === 0)

};