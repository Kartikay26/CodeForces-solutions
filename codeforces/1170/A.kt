// kartikay26

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
	var n = readInt()
	for (i in 1..n){
		var (a,b) = readInts()
		var x = 0
		var y = 0
		var z = 0
		if (a > b){
			x = a-b+1
			y = 1
			z = b-1
		} else {
			x = b-a+1
			y = 1
			z = a-1
		}
		println("$x $y $z")
	}
}
