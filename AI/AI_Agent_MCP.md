## Agentic AI
- Agentic AI refers to artificial intelligence systems designed to act as autonomous agents that can reason, plan, and execute multi-step tasks independently to achieve a specific goal. Unlike traditional generative AI, which simply responds to prompts with text, Agentic AI iteratively decides which actions to take, utilizes external tools, and self-corrects along the way. 
------------------------------
## How Agentic AI Works
Agentic AI operates via a continuous feedback loop often referred to as the 
```code
Agentic Loop (Perception → Reasoning → Action → Learning).

 [ User Goal ] 
       │
       ▼
 ┌───────────┐       ┌───────────┐
 │  Request  │ ───>  │ Reasoning │
 └───────────┘       └─────┬─────┘
       ▲                   │ (Plan)
       │ (Result)          ▼
 ┌───────────┐       ┌───────────┐
 │ Learning  │ <───  │  Action   │
 └───────────┘       └───────────┘

```
1. `Goal Setting & Perception`: The user provides a high-level goal (e.g., "Research and compile a report on market trends").
2. `Planning & Reasoning`: The core Large Language Model (LLM) breaks the goal down into smaller sub-tasks. It determines what information it lacks and creates a step-by-step strategy.
3. `Execution (Action)`: The agent invokes external tools (like web search, file access, or databases) to fetch data or execute code. 
4. `Reflection & Learning`: The agent reviews the results of its action. If an unexpected error or bad result occurs, it updates its plan and tries a different approach until the goal is met.

------------------------------
## How the MCP Server Works with an AI Agent
The Model Context Protocol (MCP), open-sourced by [Anthropic](https://www.anthropic.com/news/model-context-protocol), acts like a universal "USB-C port" for AI applications. Historically, developers had to write custom, hard-coded code (bespoke wrappers) for every single tool an agent needed to use. MCP standardizes how AI models securely communicate with data sources and tools.

## The MCP Architecture
MCP uses a simple client-server model over JSON-RPC 2.0 protocol:

```code
┌─────────────────────────────────────────┐
│           AI AGENT SYSTEM               │
│  ┌─────────────┐       ┌─────────────┐  │      JSON-RPC      ┌────────────────┐
│  │  LLM Brain  │ <───> │ MCP Client  │  │◄──────────────────►│   MCP Server   │◄───► [Local Files, APIs,
│  └─────────────┘       └─────────────┘  │ (via stdio/WebSock)└────────────────┘       Databases, etc.]
└─────────────────────────────────────────┘
```

- `The Host Application / AI Agent`: The overall application (e.g., an IDE like Cursor, or an autonomous framework) that dictates the AI's orchestration logic.
- `The MCP Client`: An integrated protocol layer within the agent system. It initiates secure connections and manages sessions with the server.
- `The MCP Server`: A lightweight, modular program that wraps around an enterprise application, a local database, or a third-party API. It exposes tools to the AI in a standard format.

## Step-by-Step Workflow Between Agent and MCP

| Step | Participant | Action Description |
|---|---|---|
| 1. Discovery | MCP Client & Server | The agent's client connects to the MCP Server and asks, "What can you do?" The server responds with a machine-readable schema describing its available tools, inputs, and constraints. |
| 2. Decision | AI Agent (LLM) | When handling a user request, the LLM determines it needs external data and chooses a specific tool it discovered from the server's list. |
| 3. Request | MCP Client | The agent does not execute the code itself. Instead, the MCP client packages the LLM's intent into a structured JSON-RPC call and sends it to the MCP Server. |
| 4. Execution | MCP Server | The server receives the instructions safely, translates them to interact with the underlying data source (e.g., running a SQL query or calling GitHub), and gathers the output. |
| 5. Context Injection | MCP Client → LLM | The server returns the structured response back to the client. The client feeds this context into the LLM's context window, allowing the agent to complete the task. |

By decoupling the tools (the server) from the reasoning system (the agent), you can swap out models or add new database capabilities instantly without rewriting the underlying application infrastructure. 