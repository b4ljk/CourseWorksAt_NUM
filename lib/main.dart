import 'package:flutter/material.dart';
import 'package:flutteratschool/second.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'hello',
      theme: ThemeData(
          primarySwatch: Colors.teal,
          elevatedButtonTheme: ElevatedButtonThemeData(
              style: ButtonStyle(
            backgroundColor: MaterialStateProperty.all<Color>(
                Color.fromARGB(255, 189, 235, 231)),
            foregroundColor: MaterialStateProperty.all<Color>(Colors.teal),
          ))),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({
    Key? key,
  }) : super(key: key);

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  get children => null;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    List items = List<int>.generate(10, (i) => i + 1);
    print(items);
    return Scaffold(
      body: Container(
        decoration: const BoxDecoration(
          color: Colors.teal,
        ),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.end,
          children: <Widget>[
            Container(
              height: 700,
              width: double.infinity,
              decoration: const BoxDecoration(
                  color: Colors.white,
                  borderRadius:
                      (BorderRadius.vertical(top: Radius.circular(20)))),
              child: Column(
                mainAxisAlignment: MainAxisAlignment.start,
                children: [
                  const SizedBox(
                    height: 40,
                  ),
                  const Text("Total balance",
                      style: TextStyle(
                          fontSize: 20,
                          color: Colors.black26,
                          fontWeight: FontWeight.bold)),
                  const SizedBox(
                    height: 20,
                  ),
                  const Text('\$25,000',
                      style: TextStyle(
                          fontSize: 40,
                          color: Colors.black,
                          fontWeight: FontWeight.bold)),
                  const SizedBox(
                    height: 25,
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Container(
                        height: 80,
                        width: 80,
                        padding: const EdgeInsets.all(20),
                        decoration: BoxDecoration(
                            border: Border.all(color: Colors.teal, width: 2),
                            borderRadius: BorderRadius.circular(100)),
                        child: const Center(
                            child: FaIcon(FontAwesomeIcons.qrcode,
                                color: Colors.teal, size: 30)),
                      ),
                      const SizedBox(
                        width: 30,
                      ),
                      Container(
                        width: 80,
                        height: 80,
                        padding: const EdgeInsets.all(20),
                        decoration: BoxDecoration(
                            border: Border.all(color: Colors.teal, width: 2),
                            borderRadius: BorderRadius.circular(100)),
                        child: const Center(
                          child: FaIcon(
                            FontAwesomeIcons.paperPlane,
                            color: Colors.teal,
                            size: 30,
                          ),
                        ),
                      ),
                      const SizedBox(
                        width: 30,
                      ),
                      Container(
                        width: 80,
                        height: 80,
                        padding: const EdgeInsets.all(20),
                        decoration: BoxDecoration(
                            border: Border.all(color: Colors.teal, width: 2),
                            borderRadius: BorderRadius.circular(100)),
                        child: const Center(
                          child: FaIcon(
                            FontAwesomeIcons.add,
                            color: Colors.teal,
                            size: 30,
                          ),
                        ),
                      ),
                    ],
                  ),
                  const SizedBox(
                    height: 20,
                  ),
                  Container(
                    margin: const EdgeInsets.symmetric(horizontal: 20),
                    padding: const EdgeInsets.all(2),
                    decoration: BoxDecoration(
                        color: Colors.grey[200],
                        border: Border.all(color: Colors.white, width: 2),
                        borderRadius: BorderRadius.circular(100)),
                    child: Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Expanded(
                            flex: 1,
                            child: TextButton(
                              onPressed: () {},
                              child: Container(
                                height: 50,
                                alignment: Alignment.center,
                                decoration: BoxDecoration(
                                    border: Border.all(
                                        color: Colors.teal, width: 2),
                                    borderRadius: BorderRadius.circular(100)),
                                child: const Text(
                                  "Transactions",
                                  textAlign: TextAlign.center,
                                  style: TextStyle(
                                      fontSize: 15,
                                      color: Colors.black,
                                      fontWeight: FontWeight.bold),
                                ),
                              ),
                            )),
                        Expanded(
                            flex: 1,
                            child: TextButton(
                              onPressed: () {
                                Navigator.push(
                                  context,
                                  MaterialPageRoute(
                                      builder: (context) => const secondpage()),
                                );
                              },
                              child: Container(
                                height: 50,
                                alignment: Alignment.center,
                                decoration: BoxDecoration(
                                    borderRadius: BorderRadius.circular(100)),
                                child: const Text(
                                  "Upcoming Bills",
                                  textAlign: TextAlign.center,
                                  style: TextStyle(
                                      fontSize: 15,
                                      color: Colors.black,
                                      fontWeight: FontWeight.bold),
                                ),
                              ),
                            )),
                      ],
                    ),
                  ),
                  const SizedBox(
                    height: 20,
                  ),
                  Column(
                    children: [
                      Column(
                        children: [
                          Padding(
                            padding: const EdgeInsets.symmetric(
                                horizontal: 40, vertical: 10),
                            child: Row(
                              children: [
                                Container(
                                  width: 40,
                                  child: const FaIcon(
                                    FontAwesomeIcons.paypal,
                                    color: Colors.blueAccent,
                                    size: 40,
                                  ),
                                ),
                                const SizedBox(
                                  width: 20,
                                ),
                                Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: const [
                                    Text("Paypal"),
                                    Text(
                                      "Today",
                                      style: TextStyle(
                                          color: Colors.grey, fontSize: 12),
                                    )
                                  ],
                                ),
                                const SizedBox(
                                  width: 120,
                                ),
                                const Text(
                                  "+ \$ 850.00",
                                  style: const TextStyle(
                                      fontSize: 20,
                                      fontWeight: FontWeight.bold,
                                      color: Colors.green),
                                )
                              ],
                            ),
                          ),
                          Padding(
                            padding: const EdgeInsets.symmetric(
                                horizontal: 40, vertical: 10),
                            child: Row(
                              children: [
                                Container(
                                  width: 40,
                                  child: const FaIcon(
                                    FontAwesomeIcons.spotify,
                                    color: Colors.green,
                                    size: 40,
                                  ),
                                ),
                                const SizedBox(
                                  width: 20,
                                ),
                                Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: const [
                                    Text("Spotify"),
                                    Text(
                                      "Today",
                                      style: TextStyle(
                                          color: Colors.grey, fontSize: 12),
                                    )
                                  ],
                                ),
                                const SizedBox(
                                  width: 120,
                                ),
                                const Text(
                                  "+ \$ 1250.0",
                                  style: TextStyle(
                                      fontSize: 20,
                                      fontWeight: FontWeight.bold),
                                )
                              ],
                            ),
                          ),
                          Padding(
                            padding: const EdgeInsets.symmetric(
                                horizontal: 40, vertical: 10),
                            child: Row(
                              children: [
                                Container(
                                  width: 40,
                                  child: const FaIcon(
                                    FontAwesomeIcons.lightbulb,
                                    color: Color.fromARGB(255, 187, 172, 40),
                                    size: 40,
                                  ),
                                ),
                                const SizedBox(
                                  width: 20,
                                ),
                                Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: const [
                                    Text("Electricity"),
                                    Text(
                                      "Today",
                                      style: TextStyle(
                                          color: Colors.grey, fontSize: 12),
                                    )
                                  ],
                                ),
                                const SizedBox(
                                  width: 110,
                                ),
                                const Text(
                                  "+ \$ 850.00",
                                  style: TextStyle(
                                      fontSize: 20,
                                      fontWeight: FontWeight.bold),
                                )
                              ],
                            ),
                          ),
                          Padding(
                            padding: const EdgeInsets.symmetric(
                                horizontal: 40, vertical: 10),
                            child: Row(
                              children: [
                                Container(
                                  width: 40,
                                  child: const FaIcon(
                                    FontAwesomeIcons.youtube,
                                    color: Colors.red,
                                    size: 40,
                                  ),
                                ),
                                const SizedBox(
                                  width: 20,
                                ),
                                Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: const [
                                    Text("Youtube"),
                                    Text(
                                      "Today",
                                      style: TextStyle(
                                          color: Colors.grey, fontSize: 12),
                                    )
                                  ],
                                ),
                                const SizedBox(
                                  width: 120,
                                ),
                                const Text(
                                  "+ \$ 850.00",
                                  style: TextStyle(
                                      color: Colors.red,
                                      fontSize: 20,
                                      fontWeight: FontWeight.bold),
                                )
                              ],
                            ),
                          )
                        ],
                      ),
                    ],
                  )
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}
