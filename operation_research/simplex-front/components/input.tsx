import React, { useState } from "react";

function MatrixInput(): JSX.Element {
	const [matrix, setMatrix] = useState<number[][]>([]);
	const [primary, setPrimary] = useState<string[]>([]);
	const [second, setSecond] = useState<string[]>([]);
	const [numRows, setNumRows] = useState<number>(3);
	const [numCols, setNumCols] = useState<number>(3);

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
		return <div>{rows}</div>;
	};

	const renderColumn = (): JSX.Element => {
		const cols: JSX.Element[] = [];
		for (let j = 0; j < numRows; j++) {
			cols.push(<input type="text" onChange={(event) => handleStringChange(event, j, primary, setPrimary)} />);
		}
		return <div style={{ display: "flex", flexDirection: "column" }}>{cols}</div>;
	};

	const renderRow = (): JSX.Element => {
		const rows: JSX.Element[] = [];
		for (let i = 0; i < numCols; i++) {
			rows.push(<input type="text" onChange={(event) => handleStringChange(event, i, second, setSecond)} />);
		}
		rows.unshift(<input readOnly value={"UNDSN/SUL"} />);
		return <div style={{ display: "flex", flexDirection: "row" }}>{rows}</div>;
	};

	return (
		<div>
			<p>Enter matrix values:</p>

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
		</div>
	);
}

export default MatrixInput;
