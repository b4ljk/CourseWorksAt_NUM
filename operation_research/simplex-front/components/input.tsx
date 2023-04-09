import axios from "axios";
import React, { useState } from "react";

function MatrixInput(): JSX.Element {
	const [matrix, setMatrix] = useState<number[][]>([]);
	const [primary, setPrimary] = useState<string[]>([]);
	const [second, setSecond] = useState<string[]>([]);
	const [numRows, setNumRows] = useState<number>(3);
	const [numCols, setNumCols] = useState<number>(3);
	const [isMaximization, setIsMaximization] = useState<boolean>(true);
	const [result, setResult] = useState<string>("");
	const handleInputChange = (event: React.ChangeEvent<HTMLInputElement>, row: number, col: number) => {
		const value = parseFloat(event.target.value);
		const newMatrix = matrix.slice();
		newMatrix[row][col] = value;
		setMatrix(newMatrix);
	};

	const handleAddRow = () => {
		const newMatrix = matrix.slice();
		const newRow = [];
		for (let j = 0; j < numCols; j++) {
			newRow.push(0);
		}
		newMatrix.push(newRow);
		setMatrix(newMatrix);
		setNumRows(numRows + 1);
	};

	const handleAddCol = () => {
		const newMatrix = matrix.slice();
		for (let i = 0; i < numRows; i++) {
			newMatrix[i].push(0);
		}
		setMatrix(newMatrix);
		setNumCols(numCols + 1);
	};

	// Initialize an empty matrix
	if (matrix.length === 0) {
		const newMatrix: number[][] = [];
		for (let i = 0; i < numRows; i++) {
			const newRow: number[] = [];
			for (let j = 0; j < numCols; j++) {
				newRow.push(0);
			}
			newMatrix.push(newRow);
		}
		setMatrix(newMatrix);
	}

	const renderInput = (row: number, col: number): JSX.Element => {
		if (matrix.length === 0) return <div></div>;
		return (
			<input type="number" value={matrix[row][col]} onChange={(event) => handleInputChange(event, row, col)} />
		);
	};

	const handleStringChange = (
		event: React.ChangeEvent<HTMLInputElement>,
		index: number,
		target: string[],
		setTarget: Function
	) => {
		const value = event.target.value;
		const newPrimary = target.slice();
		newPrimary[index] = value;
		setTarget(newPrimary);
	};

	const renderMatrix = (): JSX.Element => {
		const rows: JSX.Element[] = [];
		for (let i = 0; i < numRows; i++) {
			const cols: JSX.Element[] = [];
			for (let j = 0; j < numCols; j++) {
				cols.push(renderInput(i, j));
			}
			rows.push(<div key={i}>{cols}</div>);
		}
		return <div style={{ overflow: "auto" }}>{rows}</div>;
	};

	const renderColumn = (): JSX.Element => {
		const cols: JSX.Element[] = [];
		for (let j = 0; j < numRows; j++) {
			cols.push(<input type="text" onChange={(event) => handleStringChange(event, j, primary, setPrimary)} />);
		}
		return <div style={{ display: "flex", flexDirection: "column", overflow: "auto" }}>{cols}</div>;
	};

	const renderRow = (): JSX.Element => {
		const rows: JSX.Element[] = [];
		for (let i = 0; i < numCols; i++) {
			rows.push(<input type="text" onChange={(event) => handleStringChange(event, i, second, setSecond)} />);
		}
		rows.unshift(<input readOnly value={isMaximization ? "MAXIMUM" : "MINIMUM"} />);
		return <div style={{ display: "flex", flexDirection: "row", overflow: "auto" }}>{rows}</div>;
	};

	const calculate = async () => {
		const result = await axios.post("http://0.0.0.0:8000/body", {
			matrix: matrix,
			primary: primary,
			second: second,
		});
		console.log(result.data?.["request_body"]);
		setResult(result.data?.["request_body"]);
	};

	return (
		<div>
			<span>Maximumchlal -&gt; </span>
			<input type="checkbox" checked={isMaximization} onChange={() => setIsMaximization(!isMaximization)} />

			{renderRow()}
			<div style={{ display: "flex" }}>
				{renderColumn()}
				{renderMatrix()}
				<button onClick={handleAddCol}>Add Column</button>
			</div>
			<button onClick={handleAddRow}>Add Row</button>
			<p>The full matrix: {JSON.stringify(matrix)}</p>
			<p>Primary is : {JSON.stringify(primary)}</p>
			<p>Second is : {JSON.stringify(second)}</p>
			<button onClick={calculate}>Calculate</button>
			<p>Result is : {result}</p>
		</div>
	);
}

export default MatrixInput;
