from fastapi import FastAPI, Header, Request
from fastapi.middleware.cors import CORSMiddleware
from calculator import Calculate
app = FastAPI()


origins = ["*"]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


@app.get("/")
async def root():
    return {"message": "Hello World ayooo broooo "}

class Body:
    def __init__(self, **kwargs):
        self.matrix = kwargs.get("matrix")
        self.primary = kwargs.get("primary")
        self.second = kwargs.get("second")

        

@app.post("/body/")
async def create_item(request: Request):
    reqData = await request.json()
    body = Body(**reqData)
    return_value = Calculate(False, body.matrix,body.primary, body.second)
    return {"request_body": return_value}