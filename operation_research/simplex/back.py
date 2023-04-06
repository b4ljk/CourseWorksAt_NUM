from fastapi import FastAPI, Header, Request
from fastapi.middleware.cors import CORSMiddleware

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


@app.post("/body/")
async def create_item(request: Request):
    body = await request.json()
    return {"request_body": body}
# uvicorn back:app --reload --host 0.0.0.0 --port 7965
