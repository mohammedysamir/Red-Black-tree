const input = document.getElementById('input')
const insertBtn = document.getElementById('insert')
const deleteBtn = document.getElementById('delete')
const clearBtn = document.getElementById('clear')

let history = []

// `make` responsible for creating diagram (constructor)
var $ = go.GraphObject.make

// 								diagram class, html container
var myDiagram = $(go.Diagram, 'tree-simple', {
	'undoManager.isEnabled': true,
	layout: $(
		go.TreeLayout, // specify a Diagram.layout that arranges trees
		{ angle: 90, layerSpacing: 35 }
	)
})

// specify diagram node template
myDiagram.nodeTemplate = $(
	go.Node,
	'Horizontal', // orientation (horiz, vertical)
	$(
		go.TextBlock,
		{ margin: 5, font: 'normal normal normal 32px sans-serif' },
		new go.Binding('text', 'key'),
		new go.Binding('stroke', 'color')
	)
)

clearBtn.onclick = function () {
	history = []
	const tree = new RBTree()

	// assign created data model to our diagram
	const model = $(go.TreeModel)
	model.nodeDataArray = treeToChart(tree._root)

	myDiagram.model = model
	input.value = null
}

insertBtn.onclick = function () {
	const tree = new RBTree()

	history.push(Number.parseInt(input.value))
	history.forEach(value => tree.insert(value))

	// assign created data model to our diagram
	const model = $(go.TreeModel)
	model.nodeDataArray = treeToChart(tree._root)

	myDiagram.model = model
	input.value = null
}

deleteBtn.addEventListener('click', () => {
	const tree = new RBTree()

	history = history.filter(value => value !== Number.parseInt(input.value))
	history.forEach(value => tree.insert(value))

	// assign created data model to our diagram
	const model = $(go.TreeModel)
	model.nodeDataArray = treeToChart(tree._root)

	myDiagram.model = model
	input.value = null
})

const color = {
	1: 'red',
	0: 'black'
}

function treeToChart(node) {
	let tree = []

	function recurse(node, parent = { data: '0' }) {
		if(!node)	return
		tree.push({
	
			key: node.data,
			parent: parent.data,
			color: color[Number(node.red)]
		})

		if (node.left) recurse(node.left, node)
		if (node.right) recurse(node.right, node)
	}

 
	recurse(node)
	return tree
}
