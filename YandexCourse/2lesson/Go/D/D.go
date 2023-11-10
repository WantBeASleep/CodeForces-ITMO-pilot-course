package main

func main () {

}

func iscentral(len int, pos int) bool {
	if len % 2 == 0 {
		return false
	}
	if pos == len / 2 {
		return true
	}
	return false
}

func cubes(len int)