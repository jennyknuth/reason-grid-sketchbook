/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

  {
"_type": "graph",
"graph": {
"attrs": {},
"coords": {
"corner": {
"attrs": {},
"data": [
0,
1,
2,
3
],
"dims": [
"corner"
]
},
"node": {
"attrs": {},
"data": [
0,
1,
2,
3,
4,
5,
6,
7,
8
],
"dims": [
"node"
]
}
},
"data_vars": {
"corners_at_face": {
"attrs": {
"cf_role": "edge_node_connectivity",
"long_name": "nodes a link tail and head",
"start_index": 0
},
"data": [
[
0,
1
],
[
0,
2
],
[
1,
3
],
[
2,
3
]
],
"dims": [
"face",
"Two"
]
},
"dual": {
"attrs": {
"cf_role": "mesh_topology",
"edge_dimension": "link",
"edge_node_connectivity": "nodes_at_link",
"face_dimension": "patch",
"face_edge_connectivity": "links_at_patch",
"face_node_connectivity": "nodes_at_patch",
"long_name": "Topology data of 2D unstructured mesh",
"node_coordinates": "x_of_node y_of_node",
"topology_dimension": 2
},
"data": "a",
"dims": []
},
"faces_at_cell": {
"attrs": {
"cf_role": "face_edge_connectivity",
"long_name": "Maps every face to its edges",
"start_index": 0
},
"data": [
[
2,
3,
1,
0
]
],
"dims": [
"cell",
"max_cell_faces"
]
},
"links_at_patch": {
"attrs": {
"cf_role": "face_edge_connectivity",
"long_name": "Maps every face to its edges",
"start_index": 0
},
"data": [
[
3,
5,
2,
0
],
[
4,
6,
3,
1
],
[
8,
10,
7,
5
],
[
9,
11,
8,
6
]
],
"dims": [
"patch",
"max_patch_links"
]
},
"mesh": {
"attrs": {
"cf_role": "mesh_topology",
"edge_dimension": "link",
"edge_node_connectivity": "nodes_at_link",
"face_dimension": "patch",
"face_edge_connectivity": "links_at_patch",
"face_node_connectivity": "nodes_at_patch",
"long_name": "Topology data of 2D unstructured mesh",
"node_coordinates": "x_of_node y_of_node",
"topology_dimension": 2
},
"data": "a",
"dims": []
},
"node_at_cell": {
"attrs": {
"cf_role": "cell_node_connectivity",
"long_name": "nodes centered at cells",
"start_index": 0
},
"data": [
4
],
"dims": [
"cell"
]
},
"nodes_at_face": {
"attrs": {
"cf_role": "face_node_connectivity",
"long_name": "nodes on either side of a face",
"start_index": 0
},
"data": [
[
1,
4
],
[
3,
4
],
[
4,
5
],
[
4,
7
]
],
"dims": [
"face",
"Two"
]
},
"nodes_at_link": {
"attrs": {
"cf_role": "edge_node_connectivity",
"long_name": "nodes a link tail and head",
"start_index": 0
},
"data": [
[
0,
1
],
[
1,
2
],
[
0,
3
],
[
1,
4
],
[
2,
5
],
[
3,
4
],
[
4,
5
],
[
3,
6
],
[
4,
7
],
[
5,
8
],
[
6,
7
],
[
7,
8
]
],
"dims": [
"link",
"Two"
]
},
"x_of_corner": {
"attrs": {
"long_name": "x",
"units": "m"
},
"data": [
0.5,
1.5,
0.5,
1.5
],
"dims": [
"corner"
]
},
"x_of_node": {
"attrs": {
"long_name": "x",
"units": "m"
},
"data": [
0,
1,
2,
0,
1,
2,
0,
1,
2
],
"dims": [
"node"
]
},
"y_of_corner": {
"attrs": {
"long_name": "y",
"units": "m"
},
"data": [
0.5,
0.5,
1.5,
1.5
],
"dims": [
"corner"
]
},
"y_of_node": {
"attrs": {
"long_name": "y",
"units": "m"
},
"data": [
0,
0,
0,
1,
1,
1,
2,
2,
2
],
"dims": [
"node"
]
}
},
"dims": {
"Two": 2,
"cell": 1,
"corner": 4,
"face": 4,
"link": 12,
"max_cell_faces": 4,
"max_patch_links": 4,
"node": 9,
"patch": 4
}
},
"href": "/graphs/raster?shape=3%2C3&spacing=1.0%2C1.0&origin=0.0%2C0.0",
"repr": "DualUniformRectilinearGraph((3, 3), spacing=(1.0, 1.0), origin=(0.0, 0.0))"
}

[@react.component]
let make = (~greeting) => {
  let (state, dispatch) = React.useReducer((state, action) =>
  switch (action) {
  | Click => {...state, count: state.count + 1}
  | Toggle => {...state, show: ! state.show}
  }, {count: 0, show: true});

  let message =
    "You've clicked this " ++ string_of_int(state.count) ++ " times(s)";
  <div>
    <button onClick={_event => dispatch(Click)}>
      {ReasonReact.string(message)}
    </button>
    <button onClick={_event => dispatch(Toggle)}>
      {ReasonReact.string("Toggle greeting")}
    </button>
    {state.show ? ReasonReact.string(greeting) : ReasonReact.null}
  </div>;
};
