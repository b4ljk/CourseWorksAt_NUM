import Head from "next/head";
import Image from "next/image";
import { Inter } from "next/font/google";
import styles from "@/styles/Home.module.css";
import { NavbarSimple } from "@/components/navbar";
import { AppShell } from "@mantine/core";
import MatrixInput from "@/components/input";

const inter = Inter({ subsets: ["latin"] });

export default function Home() {
	return (
		<>
			<AppShell
				navbar={
					<NavbarSimple>
						<div>a</div>
					</NavbarSimple>
				}
			>
				<MatrixInput></MatrixInput>
			</AppShell>
		</>
	);
}
